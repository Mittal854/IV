document.addEventListener('DOMContentLoaded', function () {
    const recipeForm = document.getElementById('recipe-form');
    const recipesContainer = document.getElementById('recipes-container');
    const noRecipesMessage = document.getElementById('no-recipes');
    let recipes = JSON.parse(localStorage.getItem('recipes')) || [];

    recipeForm.addEventListener('submit', function (event) {
        event.preventDefault();
        var loggedIn = checkLoggedIn();

        if (!loggedIn) {
            alert("You are not logged in!");
            togglePopup();
            return;
        }

        const index = document.getElementById('recipe-index').value;
        const name = document.getElementById('recipe-name').value.trim();
        const ingredients = document.getElementById('recipe-ingredients').value.trim();
        const method = document.getElementById('recipe-method').value.trim();

        if (name && ingredients && method) {
            if (index !== '') {
                recipes[index] = { name: name, ingredients: ingredients, method: method };
            } else {
                recipes.push({ name: name, ingredients: ingredients, method: method });
            }
            updateRecipeList();
            recipeForm.reset();
            saveRecipesToLocalStorage();
        } else {
            alert('Please fill in all fields.');
        }
    });

    function updateRecipeList() {
        recipesContainer.innerHTML = '';
        recipes.forEach(function (recipe, index) {
            const recipeCard = document.createElement('div');
            recipeCard.classList.add('recipe-card');
            recipeCard.innerHTML = `
                <h3>${recipe.name}</h3>
                <p><strong>Ingredients:</strong> ${recipe.ingredients}</p>
                <p><strong>Method:</strong> ${recipe.method}</p>
                <button class="edit-button" data-index="${index}">Edit</button>
                <button class="delete-button" data-index="${index}">Delete</button>
                <button class="share-button" data-index="${index}">Share</button>`;
            recipesContainer.appendChild(recipeCard);
        });

        if (recipes.length === 0) {
            noRecipesMessage.style.display = 'block';
        } else {
            noRecipesMessage.style.display = 'none';
        }
    }

    function saveRecipesToLocalStorage() {
        localStorage.setItem('recipes', JSON.stringify(recipes));
    }

    function checkLoggedIn() {
        var isLoggedIn = localStorage.getItem('isLoggedIn');
        return isLoggedIn === 'true';
    }

    recipesContainer.addEventListener('click', function (event) {
        const target = event.target;
        if (target.classList.contains('delete-button')) {
            var loggedIn = checkLoggedIn();
            if (!loggedIn) {
                alert("You are not logged in!");
                togglePopup();
                return;
            }

            const index = target.dataset.index;
            recipes.splice(index, 1);
            updateRecipeList();
            saveRecipesToLocalStorage();
        } 
        else if (target.classList.contains('edit-button')) {
            var loggedIn = checkLoggedIn();
            if (!loggedIn) {
                alert("You are not logged in!");
                togglePopup();
                return;
            }

            const index = target.dataset.index;
            const recipe = recipes[index];
            document.getElementById('recipe-index').value = index;
            document.getElementById('recipe-name').value = recipe.name;
            document.getElementById('recipe-ingredients').value = recipe.ingredients;
            document.getElementById('recipe-method').value = recipe.method;
        } 
        else if (target.classList.contains('share-button')) {
            var loggedIn = checkLoggedIn();
            if (!loggedIn) {
                alert("You are not logged in!");
                togglePopup();
                return;
            }

            const index = target.dataset.index;
            const recipe = recipes[index];
            const shareMessage = `Check out this recipe: ${recipe.name}\nIngredients: ${recipe.ingredients}\nMethod: ${recipe.method}`;
            shareRecipe(shareMessage);
            alert('Your recipe is shared!');
        }
    });

    function shareRecipe(message) {
        const subject = 'Check out this recipe!';
        const recipient = "realmrecipe@gmail.com";
        const body = encodeURIComponent(message);

        const mailtoLink = `mailto:${recipient}?subject=${subject}&body=${body}`;

        window.location.href = mailtoLink;

    }

    updateRecipeList();
});