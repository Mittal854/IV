import React, { Component } from "react";
class Student extends Component {
	/*constructor(props) {
		super(props);
		this.handleClick=this.handleClick.bind(this);
	}*/
	/*handleClick(){*/
		handleClick = () => {
		console.log("button clicked",this);
	}
	render() {
		return (
		<div>
		<h1> Hello  REact</h1>
		<button onClick={this.handleClick}>click me</button>
		</div>
		);
	}
}
export default Student;

