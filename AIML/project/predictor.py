import pickle
import streamlit as st
from streamlit_option_menu import option_menu
import os


working_dir=os.path.dirname(os.path.abspath(__file__))
wine_model=pickle.load(open('wine_quality_model','rb'))
st.title('Wine Quality Prediction')
st.write('This is a simple Wine Quality Prediction App')
st.write('Please input the following features to get the prediction')
fixed_acidity=st.number_input('Fixed Acidity')
volatile_acidity=st.number_input('Volatile Acidity')
citric_acid=st.number_input('Citric Acid')
residual_sugar=st.number_input('Residual Sugar')
chlorides=st.number_input('Chlorides')
free_sulfur_dioxide=st.number_input('Free Sulfur Dioxide')
total_sulfur_dioxide=st.number_input('Total Sulfur Dioxide')
density=st.number_input('Density')
pH=st.number_input('pH')
sulphates=st.number_input('Sulphates')
alcohol=st.number_input('Alcohol')

wine_diag=''

if(st.button("Wine Quality")):
    wine_pred=wine_model.predict([[fixed_acidity,volatile_acidity,citric_acid,residual_sugar,chlorides,free_sulfur_dioxide,total_sulfur_dioxide,density,pH,sulphates,alcohol]])
    if(wine_pred==0):
        wine_diag='Bad Quality Wine'
    else:
        wine_diag='Good Quality Wine'
    st.success(wine_diag)