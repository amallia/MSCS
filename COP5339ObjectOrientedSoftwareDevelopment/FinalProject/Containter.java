import java.util.Vector;

public class Containter {
  /* {author=Christopher Foley}*/


  public Integer length;

  public Integer width;

  public Integer height;

  public Integer tareWeight;

  public Integer netWeight;

  public Integer maxWeight;


  public Integer cargoUnitId;

    public Location storedAt;
    public Vector  myShipStay;
    public Vector  myContainerDecorator;
    
    public Vector  myContainerDbAdaptor;
    
  public Containter()
  {
	  length = 96;

	  width = 106;

	  height = 96;

	  tareWeight = 1429;

	  netWeight = 8571;

	  maxWeight = 10000;


	  cargoUnitId = -1;
  
  }

  public Containter(Integer length, Integer width, Integer height, Integer tare, Integer netWeight, Integer maxWeight) {
	  this.height = height;
	  this.width = width;
	  this.length = length;
	  this.tareWeight = tare;this.netWeight = netWeight;
	  this.maxWeight = maxWeight;
  }

}