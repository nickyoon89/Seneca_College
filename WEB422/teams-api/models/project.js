var mongoose = require('mongoose');
var Schema = mongoose.Schema;

// create the projectSchema
var projectSchema = new Schema({
    ProjectName: String,
    ProjectDescription: String,
    ProjectStartDate: Date,
    ProjectEndDate: Date
});

// make this schema available to the Node application
module.exports = projectSchema;