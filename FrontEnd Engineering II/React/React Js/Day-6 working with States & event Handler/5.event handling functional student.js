import React, { Component } from "react";
function Student(props){
	function handleClick() {
		console.log("button clicked");
	}
	return (
	<div>
	<h1>hello {props.name} </h1>
	<button onClick={handleClick}>click me</button>
	</div>
	);
}
export default Student;

