import { Component, OnInit, OnDestroy } from '@angular/core';
import { EmployeeService } from '../employee.service';
import { Employee } from '../employee';

@Component({
  selector: 'app-employees',
  templateUrl: './employees-component.component.html',
  styleUrls: ['./employees-component.component.css']
})

export class EmployeesComponent implements OnInit {

  private employees: Employee[];
  private getEmployeesSub;
  private loadingError: boolean = false;

  constructor(private e: EmployeeService) { }

  ngOnInit() {
    this.getEmployeesSub = this.e.getEmployees()
    .subscribe(
      employees => this.employees = employees,
      function(e) { this.loadingError = true; }
    );
  }

  ngOnDestroy() {
    if(this.getEmployeesSub != 'undefined') {
      this.getEmployeesSub.unsubscribe();
    }
  }

}