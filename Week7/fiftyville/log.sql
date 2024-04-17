-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Taking a look at the incident report to fidn out when the crime occured
SELECT description FROM crime_scene_reports
    WHERE month = 7 AND day = 28
    AND street = 'Humphrey Street';

-- Take a look at interiews from when the incident happened
SELECT transcript FROM interviews
    WHERE year = 2021 AND month = 7 AND day = 28;


-- Take a look at security logs from when the thief drove off from the bakery, found 8 cars that left
SELECT license_plate FROM bakery_security_logs
    WHERE year= 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND minute > 15 AND activity = 'exit';


-- Checked who the cars belonged to
SELECT id FROM people
    WHERE license_plate IN
    (SELECT license_plate FROM bakery_security_logs
        WHERE year= 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND minute > 15 AND activity = 'exit');


-- Checked who withdrew money from the atm on that day, found 8 matches
SELECT account_number FROM atm_transactions
    WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';


-- Checked who the accounts belonged to
SELECT person_id FROM bank_accounts
    WHERE account_number IN
    (SELECT account_number FROM atm_transactions
        WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');


-- Checked who called for less than a minute on that day
SELECT id FROM people
    WHERE phone_number IN
    (SELECT caller FROM phone_calls
        WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60);


-- Find out what's the earliest flight out of the city on the next day
SELECT id, hour, minute FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29
    AND origin_airport_id IN (SELECT id FROM airports WHERE city = 'Fiftyville');


-- Find out who was on the flight
SELECT passport_number FROM passengers
    WHERE flight_id = 36;


--Find out which city the thief went to
SELECT city FROM flights, airports
    WHERE fligths.destination_airport_id = airports.id
    AND flights.id = 36;


-- Find out who Bruce called
SELECT caller, reciever FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller = '(367) 555-5533';

SELECT name FROM people
    WHERE phone_number = '(375) 555-8161';