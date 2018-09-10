import { Component, OnInit } from '@angular/core';
import { DataManagerService } from "./data-manager.service";

import { Post } from "./vm-typicode";

@Component({
  selector: 'app-start',
  templateUrl: './start.component.html',
  styleUrls: ['./start.component.css']
})
export class StartComponent implements OnInit {

  // Fields

  teachers: string[];
  posts: Post[];

  constructor(private m: DataManagerService) { }

  ngOnInit() {
    this.teachers = this.m.getTeachers();
    //this.getTeachers();
    //this.getPosts();
  }

  // Functions

  getTeachers(): void {
    this.teachers = this.m.getTeachers();
  }

  getPosts(): void {
    this.m.getPosts()
    .subscribe(posts => this.posts = posts);
  }
}
