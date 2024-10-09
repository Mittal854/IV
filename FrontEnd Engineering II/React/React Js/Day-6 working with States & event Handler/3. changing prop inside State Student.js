import React, { Component } from "react";
class Student extends Component {
	state = {
		name :"React",
		Technology : this.props.Technology
	};
	render() {
		return (<h1> Hello {this.state.name} your Course is 
		{this.state.Technology}</h1>
			);
	}
}
export default Student;

