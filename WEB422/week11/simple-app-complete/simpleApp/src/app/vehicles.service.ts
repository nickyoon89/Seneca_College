import { Injectable } from '@angular/core';
import {Vehicle} from './Vehicle';
import {HttpClient} from '@angular/common/http';
import { Observable } from 'rxjs';


@Injectable({
  providedIn: 'root'
})
export class VehiclesService {

  constructor(private http:HttpClient) { }

  getVehicles():Observable<Vehicle[]>{
    return this.http.get<Vehicle[]>("http://localhost:8080/api/vehicles")
  }
}

