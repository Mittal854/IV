function togglePopup() {
    var popup1 = document.getElementById("popup-1");
    var popup2 = document.getElementById("popup-2");

    popup1.classList.toggle("active");
    if (popup2.classList.contains("active")) {
        popup2.classList.remove("active");
    }
}

function togglePopup1() {
    var popup1 = document.getElementById("popup-1");
    var popup2 = document.getElementById("popup-2");

    popup2.classList.toggle("active");
    if (popup1.classList.contains("active")) {
        popup1.classList.remove("active");
    }
}

// Register Functionality
function register() {
    var name = document.getElementById("registerName").value;
    var phoneNumber = document.getElementById("registerPhoneNumber").value;
    var email = document.getElementById("registerEmail").value;
    var password = document.getElementById("registerPassword").value;

    if (name === "" || phoneNumber === "" || email === "" || password === "") {
        alert("Please fill in all fields");
        return;
    }

    var num = /^[789]\d{9}$/;
    if(!phoneNumber.match(num)) {
        alert('Invalid Phone Number');
        return false;
    }

    var mailformat = /^[a-z0-9]+@[a-z]+\.[a-z]{2,3}$/;
    if(!email.match(mailformat)) {
        alert('Invalid email');
        return false;
    }

    var userData = {
        name: name,
        phoneNumber: phoneNumber,
        email: email,
        password: password
    };

    localStorage.setItem(email, JSON.stringify(userData));

    alert("Registration successful");
    togglePopup();
}

// Login Functionality
function login() {
    var email = document.getElementById("loginEmail").value;
    var password = document.getElementById("loginPassword").value;

    var userData = JSON.parse(localStorage.getItem(email));

    if (userData && userData.password === password) {
        alert("Login successful");
        localStorage.setItem('isLoggedIn', 'true');
        document.getElementById("logoutButton").style.display = "inline";
        document.getElementById("loginBtn").style.display = "none";
    } else {
        alert("Invalid email or password");
    }
    togglePopup();
}

// Logout Functionality
function logout() {
    document.getElementById("logoutButton").style.display = "none";
    document.getElementById("loginEmail").value = "";
    document.getElementById("loginPassword").value = "";
    document.getElementById("loginBtn").style.display = "inline";
    localStorage.setItem('isLoggedIn', 'false');
    alert("You are now logged out!");
    togglePopup();
}

function initializePage() {
    var isLoggedIn = localStorage.getItem('isLoggedIn');
    if (isLoggedIn === 'true') {
        document.getElementById("logoutButton").style.display = "inline";
        document.getElementById("loginBtn").style.display = "none";
    } else {
        document.getElementById("logoutButton").style.display = "none";
        document.getElementById("loginBtn").style.display = "inline";
    }
}

// Call the initialization function when the page loads
window.onload = initializePage;

// Change Image
var index = 0;
change();

function change() {
    var x = document.getElementsByClassName('home1');
    for (var i = 0; i < x.length; i++) {
        x[i].style.display = "none";
    }
    index++;
    if (index > x.length) {
        index = 1;
    }
    x[index - 1].style.display = "block";
    setTimeout(change, 2000);
}

// Sliding Categories
const cat = [...document.querySelectorAll('.cat')];
const nextbtn = [...document.querySelectorAll('.next-btn')];
const prebtn = [...document.querySelectorAll('.pre-btn')];

cat.forEach((item, i) => {
    let dimensions = item.getBoundingClientRect();
    let wid = dimensions.width;

    nextbtn[i].addEventListener('click', () => {
        item.scrollLeft += wid;
    })

    prebtn[i].addEventListener('click', () => {
        item.scrollLeft -= wid;
    })
})