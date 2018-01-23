import java.util.Vector;

public class CompositeLocation extends Location {
  /* {author=Christopher Foley}*/


  /** 
   *  location of composite location, see subsection for refinement
   */
  public Integer location;

  public Location subsection;

    public Vector  myLocation;

  protected Location findLocation() {
  return null;
  }

}