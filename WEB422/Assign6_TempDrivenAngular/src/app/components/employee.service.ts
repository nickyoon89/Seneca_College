import { Injectable } from '@angular/core';
import { Observable} from "rxjs";
import { HttpClient} from "@angular/common/http"

import { Employee } from './employee';
import {EmployeeRaw} from './employeeRaw';

@Injectable()
export class EmployeeService {

  private url = "https://web422-server.herokuapp.com";

  constructor(private http: HttpClient) { }

  getEmployees(): Observable<Employee[]> {
    return this.http.get<Employee[]>(this.url+'/employees')
  }

  saveEmployee(employee: EmployeeRaw){
    return this.http.put<any>(
      "https://web422-server.herokuapp.com/employee/" + employee._id, employee
    );
  }

  getEmployee(id){
    return this.http.get<EmployeeRaw[]>(
      "https://web422-server.herokuapp.com/employee-raw/" + id
    );
  }
}