document.addEventListener('DOMContentLoaded', function() {

    let wrongs = document.querySelectorAll('#wrong');
    for (let i = 0; i < wrongs.length; i++) {
        wrongs[i].addEventListener('click', function() {
            wrongs[i].style.backgroundColor = 'red';
            document.querySelector('#multi_feedback').innerHTML = 'Wrong!';
        });
    }

    let right = document.querySelector('#right');
    right.addEventListener('click', function() {
        right.style.backgroundColor = 'green';
        document.querySelector('#multi_feedback').innerHTML = 'Correct!';
    });

    document.querySelector('#check').addEventListener('click', function() {
        let input = document.querySelector('input');
        let correct_answer = 'Husky';
        if (input.value == correct_answer){
            input.style.backgroundColor = 'green';
            document.querySelector('#free_feedback').innerHTML = 'Correct!';
        } else {
            input.style.backgroundColor = 'red';
            document.querySelector('#free_feedback').innerHTML = 'Wrong!';
        }
    });
});