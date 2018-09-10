import { Component, OnInit } from '@angular/core';
import { BearModel } from "../app/bear-model";
import { NgForm } from "@angular/forms";

@Component({
  selector: 'app-bear',
  templateUrl: './bear.component.html',
  styleUrls: ['./bear.component.css']
})
export class BearComponent implements OnInit {

  courses: BearModel[] = [];

  course: BearModel;

  constructor() {
    // Courses collection
    this.courses.push(new BearModel('DBW624', 'Data Warehousing', 4, "The data warehousing marketplace continues to be one of the fastest growing areas of technology application. Whether it's used with CRM, ERP, e-Commerce, Financial Analysis, Sales Analysis or any of a large number of other disciplines, data warehousing has become an essential business tool for making informed decisions. This subject introduces students to data warehousing concepts."));
    this.courses.push(new BearModel('GAM532', 'Game Engine Techniques', 4, "This course expands on basic graphics engine design to include shader programs and lighting techniques. This course also introduces engine design techniques for retrieving user input and interacting with audio hardware to produce 3D sound effects."));
    this.courses.push(new BearModel('MAP524', 'Mobile App Dev - Android', 4, "This course will familiarize the student with all aspects of planning, developing and testing mobile applications for the Android platform. It will emphasize the creation of applications using the Java programming language, as well as programming techniques for achieving effective interaction on mobile devices."));

    // New empty course
    this.course = new BearModel();
  }

  ngOnInit() {
  }

  onSubmit(f: NgForm): void {
    
    // Add to collection
    this.courses.push(this.course);

    // Refresh the form
    this.course = new BearModel();
    let input: any = document.querySelector('input[name=code]');
    input.focus();
  }

}
