let cartItems = [];

function addtocart(productName, price, imageUrl) {
  if (!isLoggedIn()) {
    alert("Please login to add items to your cart.");
    window.location.href = "signin.html";
    return;
  }

  let quantity = parseInt(document.getElementById("myNum").value);

  let itemIndex = cartItems.findIndex(
    (item) => item.productName === productName
  );

  if (itemIndex !== -1) {
    cartItems[itemIndex].quantity += quantity;
  } else {
    cartItems.push({
      productName: productName,
      price: price,
      quantity: quantity,
      imageUrl: imageUrl,
    });
  }

  saveCartToLocalStorage();
  alert("Item added to cart");
  document.getElementById("addToCartButton").textContent = "Added";

  displayCart();
  updateCartSummary();
}

function displayCart() {
  let gridContainer = document.querySelector("#cart-grid");

  gridContainer.innerHTML = "";

  cartItems.forEach((item) => {
    let gridItem = document.createElement("div");
    gridItem.classList.add("cart-item");

    gridItem.innerHTML = `
            <div class="cart-remove"><i class="fa-sharp fa-solid fa-xmark" style="padding:15px" onclick="removeItem('${
              item.productName
            }')"></i></div>
            <div class="cart-product-image"><img src="${item.imageUrl}" alt="${
      item.productName
    }" width="70"></div>
            <div class="cart-product">${item.productName}</div>
            <div class="cart-price">${item.price}</div>
            <div class="cart-quantity">${item.quantity}</div>
            <div class="cart-subtotal">${item.price * item.quantity}</div>
        `;

    gridContainer.appendChild(gridItem);
  });
}

function removeItem(productName) {
  let itemIndex = cartItems.findIndex(
    (item) => item.productName === productName
  );

  if (itemIndex !== -1) {
    cartItems.splice(itemIndex, 1);
  }

  saveCartToLocalStorage();

  displayCart();
  updateCartSummary();
}

function saveCartToLocalStorage() {
  localStorage.setItem("cartItems", JSON.stringify(cartItems));
}

function loadCartFromLocalStorage() {
  let storedCartItems = localStorage.getItem("cartItems");
  if (storedCartItems) {
    cartItems = JSON.parse(storedCartItems);
  }
}

document.addEventListener("DOMContentLoaded", function () {
  loadCartFromLocalStorage();

  displayCart();
  updateCartSummary();
});

function updateCartSummary() {
  let totalItems = 0;
  let totalPrice = 0;
  const GST_RATE = 0.18;
  const cartSummaryContainer = document.getElementById("cart-summary");
  const cartSummaryHeading = document.getElementById("cart-summary-heading");

  cartSummaryContainer.innerHTML = "";

  cartSummaryHeading.textContent = "Cart Summary";

  cartItems.forEach((item) => {
    totalItems += item.quantity;
    totalPrice += item.price * item.quantity;
  });

  const GST = totalPrice * GST_RATE;
  const totalPriceBeforeGST = totalPrice;
  totalPrice += GST;

  const totalItemsElement = document.createElement("div");
  totalItemsElement.textContent = `Total Items: ${totalItems}`;

  const totalPriceElement = document.createElement("div");
  totalPriceElement.textContent = `Total Price (incl. GST): ${formatCurrency(
    totalPrice
  )}`;

  const gstElement = document.createElement("div");
  gstElement.textContent = `GST (18%): ${formatCurrency(GST)}`;

  const totalPriceBeforeGSTElement = document.createElement("div");
  totalPriceBeforeGSTElement.textContent = `Price Before GST: ${formatCurrency(
    totalPriceBeforeGST
  )}`;

  cartSummaryContainer.appendChild(totalItemsElement);
  cartSummaryContainer.appendChild(totalPriceBeforeGSTElement);
  cartSummaryContainer.appendChild(gstElement);
  cartSummaryContainer.appendChild(totalPriceElement);
}
function formatCurrency(amount) {
  const formattedAmount = amount.toLocaleString("en-IN", {
    style: "currency",
    currency: "INR",
  });

  return formattedAmount;
}

function checkout() {
  cartItems = [];

  saveCartToLocalStorage();

  displayCart();

  updateCartSummary();

  alert("Checkout Successfully...");
  window.location.href = "index.html";
}
function isLoggedIn() {
  return localStorage.getItem("loggedIn") === "true";
}
