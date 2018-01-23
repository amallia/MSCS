

public class FragileCrane extends Crane {

  private final boolean isFragile = true;

    public FragileCrane()
    {
    	super(15200);		// initialize to 1/2 intermodal weight
    }
    /**
   * 
   * @precondition moveFragile: isFragile = true 
   */
  public void move() {
	  super.move();
  }

    /**
   * 
   * @precondition fragilePickup: isFragile = true 
   */
  public void pickup() {
	  super.pickup();
  }

    /**
   * 
   * @precondition fragileDeliver: isFragile = true 
   */
  public void deliver() {
	  super.deliver();
  }

}