import {Component} from '@angular/core';
import { PageService } from './page.service';

@Component({
  selector: 'app-page',
  templateUrl:'./page.component.html',
  styleUrls: ['./page.component.css']

})
export class PageComponent{
  location="";
  locdetails$;
  weatherdetails$;
  response:any;
  latitude:String;
  longitude:String;
  weather:String;
  temperature:String;
  windspeed:String;
  humidity:String;
  icon:String;
  status:boolean;
  constructor(private pageService: PageService){
  }

  formSubmit(){
    if(this.location=="")
    {
      this.status=false;
      return;
    }
    this.status=true;
    this.locdetails$=this.pageService.locationGet(this.location);
    this.locdetails$.subscribe((res)=>{
      this.response=res;
      this.latitude=this.response.results[0].locations[0].displayLatLng.lat;
      this.longitude=this.response.results[0].locations[0].displayLatLng.lng;
      this.weatherdetails$=this.pageService.getWeather(this.latitude,this.longitude);
      this.showWeather();
      });
 }
 showWeather(){
  this.weatherdetails$.subscribe((res)=>{
      console.log(res);
      this.weather=res.weather[0].main;
      this.temperature=res.main.temp+"\xB0C";
      this.windspeed=res.wind.speed+"km/h";
      this.humidity=res.main.humidity+"%";
      this.icon="http://openweathermap.org/img/wn/"+res.weather[0].icon+"@2x.png";
  })
 }
}
