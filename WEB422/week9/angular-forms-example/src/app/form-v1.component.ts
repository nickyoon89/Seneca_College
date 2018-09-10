import { Component, OnInit } from '@angular/core';

import { FormHero } from "../app/form-hero";

@Component({
  selector: 'app-form-v1',
  templateUrl: './form-v1.component.html',
  styleUrls: ['./form-v1.component.css']
})
export class FormV1Component implements OnInit {

  powers = ['Really smart', 'Super flexible', 'Super hot', 'Weather changer'];

  model = new FormHero(18, 'Dr. IQ', this.powers[0], 'Chuck Overstreet');

  submitted = false;

  constructor() { }

  ngOnInit() {
  }

  onSubmit() { this.submitted = true; }

  // The following will be removed
  get diagnostic() { return JSON.stringify(this.model); }

}
