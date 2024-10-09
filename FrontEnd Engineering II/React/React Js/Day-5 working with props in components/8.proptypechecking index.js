import React from "react";
import ReactDOM from "react-dom";
import Student from "./Student";


ReactDOM.render(
<Student name="React JS" 
sallary="{23000}"/>, 
document.getElementById("root"));
//ReactDOM.render(<Student name={1212} sallary="23000"/>, document.getElementById("root"));
//we want to put restriction that name should be string only