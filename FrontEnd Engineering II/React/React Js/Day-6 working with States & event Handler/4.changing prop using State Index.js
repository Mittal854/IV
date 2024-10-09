

import React,{StrictMode} from "react";
import ReactDOM from "react-dom";
import {createRoot} from 'react-dom/client';
import Student from "./Student";

const root=createRoot(document.getElementById("root"));
root.render(
<StrictMode>
<Student Technology="Full-Stack"/>
</StrictMode>
);
//ReactDOM.render(<Student Technology="Full-Stack"/>, document.getElementById("root"));
