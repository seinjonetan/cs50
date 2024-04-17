import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    person = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
    stocks = db.execute("SELECT stock, SUM(shares) AS shares FROM stocks WHERE users_id = ? GROUP BY stock", session["user_id"])
    sold = db.execute("SELECT symbol AS stock, SUM(shares) AS shares FROM sale WHERE users_id = ?", session["user_id"])
    info = {}
    total_stock_value = 0
    for stock in stocks:
        stock_name = stock["stock"]
        info[stock_name] = lookup(stock_name)
        info[stock_name].update({"bought" : stock["shares"]})
        info[stock_name].update({"remain" : stock["shares"]})
    for stock in sold:
        stock_name = stock["stock"]
        try:
            info[stock_name].update({"remain" : info[stock_name]["bought"] - stock["shares"]})
        except:
            break
    for stock in info:
        total_stock_value += info[stock]["price"] * info[stock]["remain"]
    total_holdings = total_stock_value + person[0]["cash"]
    return render_template("index.html", person=person, info=info, total_holdings=total_holdings)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if symbol == None and shares <= 0:
            return apology("Input a valid stock and number of shares", 403)
        else:
            cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
            purchase = lookup(symbol)
            total_price = purchase["price"] * float(shares)
            if cash[0]["cash"] >= total_price:
                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash[0]["cash"] - total_price, session["user_id"])
                db.execute("INSERT INTO stocks (users_id, stock, shares, time, price) VALUES (?, ?, ?, ?, ?)", session["user_id"], symbol, shares, datetime.now(), purchase["price"])
                return redirect("/")
            else:
                return apology("Not enough cash", 403)

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    purchase = db.execute("SELECT * FROM stocks WHERE users_id = ? ORDER BY time", session["user_id"])
    sale = db.execute("SELECT * FROM sale WHERE users_id = ? ORDER BY time", session["user_id"])

    return render_template("history.html", purchase=purchase, sale=sale)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        symbol = request.form.get("symbol")

        if symbol != None:
            results = lookup(symbol)
            return render_template("quoted.html", results=results)

        else:
            return apology("Input a stock symbol", 403)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if password == confirmation and password != None and confirmation != None:
            hash = generate_password_hash(confirmation)
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)
            return redirect("/login")

        else:
            return apology("passwords do not match", 403)

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        stocks = db.execute("SELECT * FROM stocks WHERE users_id = ?", session["user_id"])
        sold = db.execute("SELECT stock, SUM(shares) AS shares FROM stocks WHERE users_id = ?", session["user_id"])
        available = {}
        for stock in stocks:
            stock_name = stock["stock"]
            available[stock_name] = {}
            available[stock_name].update({"bought" : stock["shares"]})
            available[stock_name].update({"remain" : stock["shares"]})
        for stock in sold:
            stock_name = stock["stock"]
            available[stock_name].update({"sold" : stock["shares"]})
            available[stock_name].update({"remain" : available[stock_name]["bought"] - available[stock_name]["sold"]})

        stock_symbols = [stock["stock"] for stock in stocks]

        if symbol in stock_symbols and shares >= 0 and available[symbol]["remain"] >= 0:
            sold = lookup(symbol)
            db.execute("INSERT INTO sale (users_id, symbol, shares, time, price) VALUES (?, ?, ?, ?, ?)", session["user_id"], symbol, shares, datetime.now(), sold["price"])
            return redirect("/")
        else:
            return apology("Enter a valid amount of shares")

    else:
        stocks = db.execute("SELECT stock, SUM(shares) AS shares FROM stocks WHERE users_id = ? GROUP BY stock", session["user_id"])
        return render_template("sell.html", stocks=stocks)

