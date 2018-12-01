import { Component, OnInit, OnDestroy } from '@angular/core';
import { EmployeeRaw } from '../employeeRaw';
import { ActivatedRoute } from '@angular/router';
import { EmployeeService } from '../employee.service';
import { PositionService } from '../position.service';
import { Position } from '../position';

@Component({
  selector: 'app-employee',
  templateUrl: './employee.component.html',
  styleUrls: ['./employee.component.css']
})
export class EmployeeComponent implements OnInit, OnDestroy {

  private paramSubScription: any;
  private employeeSubscription: any;
  private getPositionsSubcription: any;
  private getPositionsSub: any;
  private saveEmployeeSubscription: any;
  private employee: EmployeeRaw; // instruction wants me to fix it to non-private but it works. so i will keep it private anyways
  private positions: Position[];
  private successMessage = false;
  private failMessage = false;

  constructor(private route: ActivatedRoute, private employeeService: EmployeeService, private positionService: PositionService) { }

  ngOnInit() {
    this.paramSubScription = this.route.params.subscribe((params) => {
      this.employeeSubscription = this.employeeService.getEmployee(params['_id']).subscribe((emp) => {
        this.employee = emp[0];

        this.getPositionsSub = this.positionService.getPositions().subscribe(data => {
          this.positions = data;
        });

      });
    });
  }

  onSubmit() {
    this.saveEmployeeSubscription = this.employeeService.saveEmployee(this.employee).subscribe(() => {
      this.successMessage = true;

      // THERE WAS ONE LINE HERE BUT DELETE

      setTimeout(() => {
        this.successMessage = false;
      }, 2500);
    },
      () => {
        this.failMessage = true;
        setTimeout(() => {
          this.failMessage = false;
        }, 2500);
      });
  }

  ngOnDestroy() {
    if (this.paramSubScription) { this.paramSubScription.unsubscribe(); }
    if (this.employeeSubscription) { this.employeeSubscription.unsubscribe(); }
    if (this.getPositionsSub) { this.getPositionsSub.unsubscribe(); }
    if (this.saveEmployeeSubscription) { this.saveEmployeeSubscription.unsubscribe(); }
  }
}
