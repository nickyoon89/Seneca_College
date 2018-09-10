import { Component, OnInit } from '@angular/core';
import { DataManagerService } from "./data-manager.service";

import { Post } from "./vm-typicode";

@Component({
  selector: 'app-horse',
  templateUrl: './horse.component.html',
  styleUrls: ['./horse.component.css']
})
export class HorseComponent implements OnInit {

  posts: Post[];
  
  constructor(private m: DataManagerService) { }

  ngOnInit() {
    this.getPosts();
  }

  getPosts(): void {
    this.m.getPosts()
    .subscribe(posts => this.posts = posts);
  }
}
