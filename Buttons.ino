int getButton()
{
  int i, z, sum;
  int button;

  sum = 0;
  for (i=0; i < 4; i++)
  {
     sum += analogRead(0);
  }
  z = sum / 4;                                         
  if (z > 1000) button = 0;                                           
  else if (z >= 0 && z < 40) button = 1;                     
  else if (z > 100 && z < 180) button = 2;                
  else if (z > 290 && z < 370) button = 3;                
  else if (z > 460 && z < 540) button = 4;             
  else if (z > 700 && z < 780) button = 5;
  else button = 0;

  return button;
}
