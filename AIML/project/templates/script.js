// Function to predict wine quality based on user input
function predictQuality() {
    // Get input values
    const fixedAcidity = parseFloat(document.getElementById("fixed-acidity").value);
    const volatileAcidity = parseFloat(document.getElementById("volatile-acidity").value);
    const citricAcid = parseFloat(document.getElementById("citric-acid").value);
    const residualSugar = parseFloat(document.getElementById("residual-sugar").value);
    const chlorides = parseFloat(document.getElementById("chlorides").value);
    const freeSulfurDioxide = parseFloat(document.getElementById("free-sulfur-dioxide").value);
    const totalSulfurDioxide = parseFloat(document.getElementById("total-sulfur-dioxide").value);
    const density = parseFloat(document.getElementById("density").value);
    const ph = parseFloat(document.getElementById("ph").value);
    const sulfates = parseFloat(document.getElementById("sulfates").value);
    const alcohol = parseFloat(document.getElementById("alcohol").value);
  
    // Replace with your actual Machine Learning model for prediction (placeholder for now)
    const predictedQuality = (fixedAcidity + volatileAcidity + citricAcid) / 3;
  
    // Update result display
    const qualityResultElement = document.getElementById("quality-result");
    qualityResultElement.textContent = `Predicted Quality: ${predictedQuality.toFixed(2)}`;
  
    // Update meter display (optional, requires additional logic based on your model's output range)
    updateQualityMeter(predictedQuality);
  }
  
  // Function to update the quality meter (example logic based on predictedQuality range)
  function updateQualityMeter(predictedQuality) {
    const qualityTextElement = document.getElementById("quality-text");
    let qualityText = "Unknown";
  
    if (predictedQuality >= 8) {
      qualityText = "Excellent";
    } else if (predictedQuality >= 7) {
      qualityText = "Very Good";
    } else if (predictedQuality >= 6) {
      qualityText = "Good";
    } else if (predictedQuality >= 5) {
      qualityText = "Average";
    } else {
      qualityText = "Below Average";
    }
  
    qualityTextElement.textContent = qualityText;
}
  
// Function to clear all input fields and result display
function clearFields() {
  // Clear input fields
  document.querySelectorAll('input[type="number"]').forEach(input => input.value = '');

  // Clear result display
  document.getElementById("quality-result").textContent = '';

  // Clear meter display (if needed)
  // document.getElementById("quality-meter").style.backgroundColor = "#ccc";
  document.getElementById("quality-text").textContent = '';
}
