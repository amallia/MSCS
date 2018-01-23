import java.util.Vector;

public class CraneView {

  public boolean validOperator;

  public Crane crane;

    public Vector  Qualified for;
    public Vector  myCrane;
    public Vector  myCraneController;

  public void validateOperator(int id) {
  }

    /**
   * 
   * @precondition validOperator: validOperator = true 
   */
  public void move(Location destination) {
  }

    /**
   * 
   * @precondition validOperator: validOperator = true 
   * @precondition weightLimit: crane . max_weight >= container . weight 
   */
  public void pickup(Container cotainer) {
  }

    /**
   * 
   * @precondition cargoPresent: crane . cargoForTransport <> 0 
   */
  public void deliver() {
  }

    /**
   * 
   * @precondition validOperator: validOperator = true 
   */
  public void activate() {
  }

  public CraneView() {
  }

}