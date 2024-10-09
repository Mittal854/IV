document.addEventListener("DOMContentLoaded", function () {
  var searchForm = document.getElementById("searchForm");
  var searchInput = document.getElementById("searchInput");
  var searchResults = document.getElementById("searchResults");

  var products = [
    {
      category: "tshirts",
      name: "OWN THE RUN HEATHER TEE",
      image: "img/tshirt1.avif",
      link: "sproduct9.html",
    },
    {
      category: "tshirts",
      name: "ESSENTIALS SINGLE JERSEY LINEAR EMBROIDERED LOGO TEE",
      image: "img/tshirt2.avif",
      link: "sproduct10.html",
    },
    {
      category: "tshirts",
      name: "BRANDLOVE TEE",
      image: "img/tshirt3.avif",
      link: "sproduct11.html",
    },
    {
      category: "tshirts",
      name: "ESSENTIALS SINGLE JERSEY BIG LOGO TEE",
      image: "img/tshirt4.avif",
      link: "sproduct12.html",
    },
    {
      category: "jackets",
      name: "BSC 3-STRIPES HOODED INSULATED JACKET",
      image: "img/jacket.avif",
      link: "sproduct1.html",
    },
    {
      category: "jackets",
      name: "ADIDAS X MARIMEKKO MARATHON JACKET",
      image: "img/jacket2.avif",
      link: "sproduct2.html",
    },
    {
      category: "jackets",
      name: "GRAPHICS CAMO COACH JACKET",
      image: "img/jacket3.jpg",
      link: "sproduct3.html",
    },
    {
      category: "jackets",
      name: "ADIDAS ADVENTURE WINTER ALLOVER PRINT GORE-TEX JACKET",
      image: "img/jacket4.avif",
      link: "sproduct4.html",
    },
    {
      category: "sweatshirts",
      name: "REAL MADRID LFSTLR HOODIE",
      image: "img/hoodie1.avif",
      link: "sproduct5.html",
    },
    {
      category: "sweatshirts",
      name: "ADIDAS MOSCOW GRAPHIC TEE",
      image: "img/hoodie2.avif",
      link: "sproduct6.html",
    },
    {
      category: "sweatshirts",
      name: "POLAR FLEECE NATURE HOODIE",
      image: "img/hoodie3.avif",
      link: "sproduct7.html",
    },
    {
      category: "sweatshirts",
      name: "Z.N.E. PREMIUM FULL-ZIP HOODED TRACK JACKET",
      image: "img/hoodie4.avif",
      link: "sproduct8.html",
    },
    {
      category: "sweaters",
      name: "High Neck Black Solid Sweater - Jester",
      image: "img/sweater1.jpg",
      link: "sproduct17.html",
    },
    {
      category: "sweaters",
      name: "Crew Neck Maroon Printed Sweater - Leech",
      image: "img/sweater2.jpg",
      link: "sproduct18.html",
    },
    {
      category: "sweaters",
      name: "Crew Neck Bottle Green Textured Sweater - Jiggle",
      image: "img/sweater3.jpg",
      link: "sproduct19.html",
    },
    {
      category: "sweaters",
      name: "High Neck Off White Textured Sweater - Jeremy",
      image: "img/sweater4.jpg",
      link: "sproduct20.html",
    },
    {
      category: "suits",
      name: "Two Piece Dark Grey Textured Formal Suits - Waves",
      image: "img/suit1.webp",
      link: "sproduct29.html",
    },
    {
      category: "suits",
      name: "Must Haves Two Piece Black Solid Formal Suit - Jerret",
      image: "img/suit2.webp",
      link: "sproduct30.html",
    },
    {
      category: "suits",
      name: "Tuxedo Three Piece Navy Textured Formal Suit - Rodrigo",
      image: "img/suit3.webp",
      link: "sproduct31.html",
    },
    {
      category: "suits",
      name: "Two Piece Navy Textured Formal Suits - Waves",
      image: "img/suit4.webp",
      link: "sproduct32.html",
    },
    {
      category: "blazers",
      name: "Formal Beige Textured Blazer - Caleb",
      image: "img/blazer1.jpg",
      link: "sproduct25.html",
    },
    {
      category: "blazers",
      name: "Casual Charcoal Textured Blazer - Lupin",
      image: "img/blazer2.jpg",
      link: "sproduct26.html",
    },
    {
      category: "blazers",
      name: "Linen Formal Light Blue Textured Blazer - Amber",
      image: "img/blazer3.jpg",
      link: "sproduct27.html",
    },
    {
      category: "blazers",
      name: "TechPro Formal Green Solid Blazer - Sein",
      image: "img/blazer4.jpg",
      link: "sproduct28.html",
    },
    {
      category: "achkans",
      name: "Swarn Multitude 6X Black Textured Achkan Set - Stapol",
      image: "img/achkan1.webp",
      link: "sproduct21.html",
    },
    {
      category: "achkans",
      name: "Swarn Two Piece Maroon Solid Achkan Set - Veltos",
      image: "img/achkan2.webp",
      link: "sproduct22.html",
    },
    {
      category: "achkans",
      name: "Swarn Two Piece Dark Green Textured Achkan Set - Dimitri",
      image: "img/achkan3.webp",
      link: "sproduct23.html",
    },
    {
      category: "achkans",
      name: "Swarn Three Piece Blue Textured Achkan Set - King",
      image: "img/achkan4.webp",
      link: "sproduct24.html",
    },

    {
      category: "shorts",
      name: "MANCHESTER UNITED 23/24 HOME SHORTS",
      image: "img/shorts1.avif",
      link: "sproduct13.html",
    },
    {
      category: "shorts",
      name: "HIIT WORKOUT 3-STRIPES SHORTS",
      image: "img/shorts2.avif",
      link: "sproduct14.html",
    },
    {
      category: "shorts",
      name: "ADIDAS SELECT SHORTS",
      image: "img/shorts3.avif",
      link: "sproduct15.html",
    },
    {
      category: "shorts",
      name: "Z.N.E. PREMIUM SHORTS",
      image: "img/shorts4.avif",
      link: "sproduct16.html",
    },
  ];

  searchForm.addEventListener("submit", function (event) {
    event.preventDefault();
    var searchTerm = searchInput.value.trim().toLowerCase();
    if (searchTerm !== "") {
      var filteredProducts = products.filter(function (product) {
        return (
          product.category.toLowerCase() === searchTerm ||
          product.name.toLowerCase().includes(searchTerm)
        );
      });

      displaySearchResults(filteredProducts);
    } else {
      hideSearchResults();
    }
  });

  function displaySearchResults(products) {
    searchResults.innerHTML = "";
    if (products.length === 0) {
      var noResultsMessage = document.createElement("div");
      noResultsMessage.textContent = "Sorry! No results found...";
      searchResults.appendChild(noResultsMessage);
      searchResults.classList.remove("hidden");
      return;
    }
    products.forEach(function (product) {
      var item = document.createElement("div");
      item.classList.add("searchItem");

      var image = document.createElement("img");
      image.src = product.image;
      image.alt = product.name;
      image.width = 70;

      var name = document.createElement("span");
      name.textContent = product.name;

      item.appendChild(image);
      item.appendChild(name);

      item.addEventListener("click", function () {
        window.location.href = product.link;
      });

      searchResults.appendChild(item);
    });

    searchResults.classList.remove("hidden");
  }

  function hideSearchResults() {
    searchResults.innerHTML = "";
    searchResults.classList.add("hidden");
  }

  document.addEventListener("click", function (event) {
    if (!searchForm.contains(event.target)) {
      hideSearchResults();
    }
  });

  searchForm.addEventListener("click", function (event) {
    event.stopPropagation();
  });
});
