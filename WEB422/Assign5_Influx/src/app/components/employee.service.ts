import { Injectable } from '@angular/core';
import { Observable} from "rxjs";
import { HttpClient} from "@angular/common/http"

import { Employee } from './employee';

@Injectable()
export class EmployeeService {

  private url = "https://web422-server.herokuapp.com";

  constructor(private http: HttpClient) { }

  getEmployees(): Observable<Employee[]> {
    return this.http.get<Employee[]>(this.url+'/employees')
  }
}