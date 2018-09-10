import { Injectable } from '@angular/core';

import { HttpClient } from "@angular/common/http";
import { Observable } from "rxjs";
//import { of } from "rxjs/observable/of";
//import { catchError, map, tap } from "rxjs/operators";

// not sure if we need tap...

import { Post, Comment, Geo, Address, Company, User } from "./vm-typicode";

@Injectable({
  providedIn: 'root'
})
export class DataManagerService {

  // Fields

  private teachers: string[] = [];

  private url = "https://jsonplaceholder.typicode.com";

    constructor(private http: HttpClient) { 
    // Load the teachers collection
    this.teachers.push('Pat');
    this.teachers.push('Peter');
    this.teachers.push('Sharmin');
    this.teachers.push('Sunny');
    this.teachers.push('James');
  }

  // Functions

  getTeachers() {
    return this.teachers;
  }

  getPosts(): Observable<Post[]> {
    return this.http.get<Post[]>(`${this.url}/posts`)
  }

  getComments(): Observable<Comment[]> {
    return this.http.get<Comment[]>(`${this.url}/comments`)
  }

  getUsers(): Observable<User[]> {
    return this.http.get<User[]>(`${this.url}/users`)
  }

}

