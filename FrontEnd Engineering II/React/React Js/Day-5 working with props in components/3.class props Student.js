
import React, { Component } from "react";
class Student extends Component {
	render() {
		return (
		<div> <h1> Hello {this.props.name}</h1> <h1> Your {this.props.sallary} </h1>
		</div>
		);
	}
}
export default Student;
