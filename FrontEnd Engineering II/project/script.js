var MainImg = document.getElementById("MainImg");
var smallimg = document.getElementsByClassName("small-img");
smallimg[0].onclick = function () {
  var temp = MainImg.src;
  MainImg.src = smallimg[0].src;
  smallimg[0].src = temp;
};
smallimg[1].onclick = function () {
  var temp = MainImg.src;
  MainImg.src = smallimg[1].src;
  smallimg[1].src = temp;
};
smallimg[2].onclick = function () {
  var temp = MainImg.src;
  MainImg.src = smallimg[2].src;
  smallimg[2].src = temp;
};
smallimg[3].onclick = function () {
  var temp = MainImg.src;
  MainImg.src = smallimg[3].src;
  smallimg[3].src = temp;
};


