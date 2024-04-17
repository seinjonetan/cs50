document.addEventListener('DOMContentLoaded', function(){

    let menu_item = document.getElementById('menu_item');

    menu_item.addEventListener('mouseover', (event) => {
        event.target.style.color = 'blue';
        setTimeout(() =>{
            event.target.style.color = "";
            }, 500);
    },
    false
    );

});