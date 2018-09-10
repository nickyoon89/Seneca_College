import { Component, OnInit } from '@angular/core';
import { DataManagerService } from "./data-manager.service";

@Component({
  selector: 'app-guide',
  templateUrl: './guide.component.html',
  styleUrls: ['./guide.component.css']
})
export class GuideComponent implements OnInit {

  // Properties

  teachers: string[];
  constructor(private m: DataManagerService) { }

  ngOnInit() {
    this.teachers = this.m.getTeachers();
  }

}
