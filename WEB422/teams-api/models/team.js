var mongoose = require('mongoose');
var Schema = mongoose.Schema;

// create the teamSchema
var teamSchema = new Schema({
    TeamName: String,
    Projects: [{ type: Schema.Types.ObjectId, ref: 'Project' }],
    Employees: [{ type: Schema.Types.ObjectId, ref: 'Employee' }],
    TeamLead: { type: Schema.Types.ObjectId, ref: 'Employee' }
});

// make this schema available to the Node application
module.exports = teamSchema;