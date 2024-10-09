import React,{StrictMode} from "react";
import ReactDOM from "react-dom";
import {createRoot} from 'react-dom/client';
import Student from "./Student";

const root=createRoot(document.getElementById("root"));
root.render(
<StrictMode>
<Student name="Group G3"/>
</StrictMode>
);
//ReactDOM.render(<Student name="react"/>, document.getElementById("root"));
