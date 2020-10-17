import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';


@Injectable({
  providedIn: 'root'
})
export class PageService {

  latitude="";
  longitude="";
  response:any;
  constructor(private http:HttpClient) { }


locationGet(location:String){
   return this.http.get('https://www.mapquestapi.com/geocoding/v1/address?key=9pVCWUXgrhjVovImTASTBnPtRYQdA6sa&location='+location);
}

getWeather(latitude:String,longitude:String){
  return this.http.get('https://api.openweathermap.org/data/2.5/weather?lat='+latitude+'&lon='+longitude+'&appid=bb5214980743a161bd07bf54510d92ff&units=metric');
}
}
