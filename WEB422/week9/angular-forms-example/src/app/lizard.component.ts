import { Component, OnInit } from '@angular/core';
import { DataManagerService } from "./data-manager.service";

import { User } from "./vm-typicode";

@Component({
  selector: 'app-lizard',
  templateUrl: './lizard.component.html',
  styleUrls: ['./lizard.component.css']
})
export class LizardComponent implements OnInit {

  users: User[];

  constructor(private m: DataManagerService) { }

  ngOnInit() {
    this.getUsers();
  }

  getUsers(): void {
    this.m.getUsers()
    .subscribe(users => this.users = users);
  }
}
