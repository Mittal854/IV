import React from "react";
import PropTypes from "prop-types";

const Student = props => {
return (
<div>
<h1> Hello {props.name}</h1>
<h2> Hello {props.sallary}</h2>
</div>
);
};
Student.propTypes = {
name: PropTypes.string.isRequired
};

Student.defaultProps = {
	name: "G11 students"
}
export default Student;
//with this in console we would get an error because of restriction
//in name variable of string type.

