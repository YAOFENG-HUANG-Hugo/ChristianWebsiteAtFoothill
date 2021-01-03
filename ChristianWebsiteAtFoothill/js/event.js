var gospel = document.getElementById("gospel");
var retreats = document.getElementById("retreats");
var n1 = 1;
var n2 = 1;

setInterval(function () {
    gospel.innerHTML = "<img src='img/EventPicture/gospel/" + n1 + ".jpg' />";
    n1++;
    if (n1 == 5) n1 = 1;
}, 3000);

setInterval(function () {
    retreats.innerHTML = "<img src='img/EventPicture/retreats/" + n2 + ".jpg' />";
    n2++;
    if (n2 == 5) n2 = 1;
}, 6500);

