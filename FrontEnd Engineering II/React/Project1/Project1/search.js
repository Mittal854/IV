document.addEventListener("DOMContentLoaded", function () {
    var searchForm = document.getElementById("searchForm");
    var searchInput = document.getElementById("searchInput");
    var searchResults = document.getElementById("searchResults");

    var products = [
        {
            category: "Breads",
            name: "Roti",
            image: "/Project1/images1/Roti.jpg",
            link: "/Project1/BreadCat/Roti.html",
        },
        {
            category: "Breads",
            name: "Rumali Roti",
            image: "/Project1/images1/RumaliRoti.jpg",
            link: "/Project1/BreadCat/RumaliRoti.html",
        },
        {
            category: "Breads",
            name: "Naan",
            image: "/Project1/images1/Naan.jpeg",
            link: "/Project1/BreadCat/Naan.html",
        },
        {
            category: "Breads",
            name: "Lachha Parantha",
            image: "/Project1/images1/LachhaParantha.jpg",
            link: "/Project1/BreadCat/LachhaParantha.html",
        },

        {
            category: "Breakfast",
            name: "Aloo Paratha",
            image: "/Project1/images1/Aloo_Parantha.jpg",
            link: "/Project1/BreakCat/AlooParantha.html",
        },
        {
            category: "Breakfast",
            name: "Banana Smoothie",
            image: "/Project1/images1/Banana.webp",
            link: "/Project1/BreakCat/BananaSmootie.html",
        },
        {
            category: "Breakfast",
            name: "Bread Pakora",
            image: "/Project1/images1/BreadPakora.cms",
            link: "/Project1/BreakCat/BreadPakora.html",
        },
        {
            category: "Breakfast",
            name: "Egg Sandwich",
            image: "/Project1/images1/EggSand.jpg",
            link: "/Project1/BreakCat/EggSand.html",
        },
        {
            category: "Breakfast",
            name: "French Toast",
            image: "/Project1/images1/FrenchToast.jpg",
            link: "/Project1/BreakCat/FrenchToast.html",
        },
        {
            category: "Breakfast",
            name: "Omlette",
            image: "/Project1/images1/Omlette.jpg",
            link: "/Project1/BreakCat/Omlette.html",
        },
        {
            category: "Breakfast",
            name: "Pancakes",
            image: "/Project1/images1/Pancakes.jpg",
            link: "/Project1/BreakCat/Pancakes.html",
        },
        {
            category: "Breakfast",
            name: "Paneer Paratha",
            image: "/Project1/images1/PaneerParatha.jpg",
            link: "/Project1/BreakCat/PaneerParatha.html",
        },

        {
            category: "Non-Veg",
            name: "Brownie",
            image: "/Project1/images1/Brownie.jpg",
            link: "/Project1/ChickenCat/Brownie.html",
        },
        {
            category: "Non-Veg",
            name: "Omlette",
            image: "/Project1/images1/Omlette.jpg",
            link: "/Project1/ChickenCat/Omlette.html",
        },
        {
            category: "Non-Veg",
            name: "Butter Chicken",
            image: "/Project1/images1/ButterChicken.jpg",
            link: "/Project1/ChickenCat/ButterChicken.html",
        },
        {
            category: "Non-Veg",
            name: "Chicken Curry",
            image: "/Project1/images1/ChickenCurry.jpg",
            link: "/Project1/ChickenCat/ChickenCurry.html",
        },
        {
            category: "Non-Veg",
            name: "Chicken Tikka",
            image: "/Project1/images1/ChickenTikka.jpg",
            link: "/Project1/ChickenCat/ChickenTIkka.html",
        },
        {
            category: "Non-Veg",
            name: "Egg Bhurji",
            image: "/Project1/images1/EggBhurji.jpg",
            link: "/Project1/ChickenCat/EggBhurji.html",
        },
        {
            category: "Non-Veg",
            name: "Egg Sandwich",
            image: "/Project1/images1/EggSand.jpg",
            link: "/Project1/ChickenCat/EggSand.html",
        },
        {
            category: "Non-Veg",
            name: "French Toast",
            image: "/Project1/images1/FrenchToast.jpg",
            link: "/Project1/ChickenCat/FrenchToast.html",
        },

        {
            category: "Desserts",
            name: "Gulab Jamun",
            image: "/Project1/images1/GulabJamun.jpeg",
            link: "/Project1/DessertCat/GulabJamun.html",
        },
        {
            category: "Desserts",
            name: "Tiramisu",
            image: "/Project1/images1/Tiramisu.jpg",
            link: "/Project1/DessertCat/Tiramisu.html",
        },
        {
            category: "Desserts",
            name: "Jalebi",
            image: "/Project1/images1/Jalebi.webp",
            link: "/Project1/DessertCat/Jalebi.html",
        },

        {
            category: "Dinner",
            name: "Bhindi Masala",
            image: "/Project1/images1/BhindiMasala.jpg",
            link: "/Project1/DinnerCat/BhindiMasala.html",
        },
        {
            category: "Dinner",
            name: "Dal Makhani",
            image: "/Project1/images1/DalMakhani.jpg",
            link: "/Project1/DinnerCat/DalMakhani.html",
        },
        {
            category: "Dinner",
            name: "Malai Kofta",
            image: "/Project1/images1/Malai_Kofta.jpg",
            link: "/Project1/DinnerCat/MalaiKofta.html",
        },
        {
            category: "Dinner",
            name: "Matar Malai Methi",
            image: "/Project1/images1/mmm.webp",
            link: "/Project1/DinnerCat/MatarMalaiMethi.html",
        },
        {
            category: "Dinner",
            name: "Moong Dal",
            image: "/Project1/images1/moongdal.jpeg",
            link: "/Project1/DinnerCat/MoongDal.html",
        },
        {
            category: "Dinner",
            name: "Paneer Bhurji",
            image: "/Project1/images1/PaneerBhurji.jpg",
            link: "/Project1/DinnerCat/PaneerBhurji.html",
        },

        {
            category: "Italian",
            name: "Alfredo Sauce Pasta",
            image: "/Project1/images1/AlfredoPasta.jpg",
            link: "/Project1/ItalianCat/AlfredoPasta.html",
        },
        {
            category: "Italian",
            name: "Arrabiata Sauce Pasta",
            image: "/Project1/images1/Arrabiata.webp",
            link: "/Project1/ItalianCat/ArrabiataPasta.html",
        },
        {
            category: "Italian",
            name: "Pizza",
            image: "/Project1/images1/Pizza.webp",
            link: "/Project1/ItalianCat/Pizza.html",
        },

        {
            category: "Lunch",
            name: "Aloo Shimlamirch",
            image: "/Project1/images1/AlooShimlaMirch.jpg",
            link: "/Project1/LunchCat/AlooShimlamirch.html",
        },
        {
            category: "Lunch",
            name: "Gobi Aloo",
            image: "/Project1/images1/AlooGobhi.jpg",
            link: "/Project1/LunchCat/GobiAloo.html",
        },
        {
            category: "Lunch",
            name: "Matar Paneer",
            image: "/Project1/images1/MatarPaneer.cms",
            link: "/Project1/LunchCat/MatarPaneer.html",
        },
        {
            category: "Lunch",
            name: "Mix Veg",
            image: "/Project1/images1/MixVeg.jpg",
            link: "/Project1/LunchCat/MixVeg.html",
        },
        {
            category: "Lunch",
            name: "Rajma Chawal",
            image: "/Project1/images1/Rajma.jpg",
            link: "/Project1/LunchCat/RajmaChawal.html",
        },
        {
            category: "Lunch",
            name: "White Chane",
            image: "/Project1/images1/WhiteChane.webp",
            link: "/Project1/LunchCat/WhiteChane.html",
        },
        {
            category: "Lunch",
            name: "Egg Curry",
            image: "/Project1/images1/EggCurry.jpg",
            link: "/Project1/ItalianCat/EggCurry.html",
        },

        {
            category: "Snacks",
            name: "Fries",
            image: "/Project1/images1/FrenchFries.webp",
            link: "/Project1/SnacksCat/AlooFries.html",
        },
        {
            category: "Snacks",
            name: "Cold Sandwich",
            image: "/Project1/images1/ColdSandwich.jpg",
            link: "/Project1/SnacksCat/ColdSandwich.html",
        },
        {
            category: "Snacks",
            name: "Crispy Corn",
            image: "/Project1/images1/CrispyCorn.webp",
            link: "/Project1/SnacksCat/CrispyCorn.html",
        },
        {
            category: "Snacks",
            name: "Dahi Bhalle",
            image: "/Project1/images1/DahiBhalle.webp",
            link: "/Project1/SnacksCat/DahiBhalle.html",
        },
        {
            category: "Snacks",
            name: "Dhokla",
            image: "/Project1/images1/dhokla.jpg",
            link: "/Project1/SnacksCat/Dhokla.html",
        },
        {
            category: "Snacks",
            name: "Samosa",
            image: "/Project1/images1/Samosa.webp",
            link: "/Project1/SnacksCat/Samosa.html",
        }
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