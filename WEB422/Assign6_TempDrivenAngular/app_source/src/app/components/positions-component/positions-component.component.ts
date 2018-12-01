import { Component, OnInit, OnDestroy } from '@angular/core';
import { PositionService } from '../position.service';
import { Position } from '../position';
import { Router } from "@angular/router";

@Component({
  selector: 'app-positions',
  templateUrl: './positions-component.component.html',
  styleUrls: ['./positions-component.component.css']
})
export class PositionsComponent implements OnInit, OnDestroy {

  private positions: Position[];
  private getPositionSub;
  private loadingError: boolean = false;

  constructor(private p : PositionService, private router: Router) { }

  ngOnInit() {
    this.getPositionSub = this.p.getPositions()
    .subscribe(
      positions => this.positions = positions,
      function(e) { this.loadingError = true; }
    );
  }

  routePosition(id: string) {
    this.router.navigate(['/position/', id]);
  }

  ngOnDestroy() {
    console.log(this.getPositionSub);
    if(this.getPositionSub != 'undefined') {
      this.getPositionSub.unsubscribe();
    }
  }

}