## Week 3 Examples

The code example this week is a single application of Knockout.js and how we can use it to work with the "Employee" data of our Teams API.  

This is done by rendering a grid of First Name / Last Name &lt;input&gt; fields and watching for changes.  A "dirty" flag is applied to all changed employees, which is used to identify which employees to update when the "Save" button is clicked .

A new promise technique is introduced (**promise.all()**) to execute AJAX **PUT** requests to our API, for all modified employees.  Once complete, each employee's "dirty" flag is removed.



