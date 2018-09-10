## Week 5 Examples

The code example this week is a single application created in React using the "create-react-app" tool. 

This example illustrates how we can use React to create a SPA (Single Page Application) with multiple routes (including those with parameters, as well as a "Not Found" page). The application also shows how we can read and write "Employee" data using our Teams API.

**Note:** To get the example working for your specific API, the App.js file (defining the routes) will need to be updated to point to your Heroku API

#### Routes

This application shows a complete set of routes for our data: ie, "/teams", "/projects", "/project/:projectId", etc.  However, all routes except "/employees and "/employee/:employeeId" simply return a "TODO" placeholder.  As an exercise, use the "Employee" routes ("/employees", "employee/:employeeId) and their corresponding components ("Employee/Employees.js" and "Employee/Employee.js") as examples and try updating the other routes on your own.  

