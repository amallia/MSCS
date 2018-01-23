import java.util.Vector;

public class Location {
  /* {author=Christopher Foley}*/


  public Location location;

    public Vector  myWarehouse;
    public Vector  SubSections;
    public Vector  myCompositeLocation;
    public Vector  storedAt;

  public Location assignLocation( Object resourceToAssign) {
	  
  return this;				// return a location null = not available
  }

  private Location findContainerLocation() {
  return null;
  }

  public Location findShipLocation() {
  return null;
  }

  private Location findLocation() {
  return null;
  }

}