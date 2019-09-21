package JCodes.SystemDesign.Parkinglot;

import java.util.Arrays;

public class Level {
    private Spot[] spots;
    private int maxSpots;
    private boolean [] occupied;
    private int availableSpots;
    private int floor;

    public Level(int floor , int maxSpots, int availableSpots) {
        this.maxSpots = maxSpots;
        this.floor = floor;
        this.availableSpots = availableSpots;
        initialize();
    }

    private void initialize() {
        spots = new Spot[maxSpots];
        occupied = new boolean[maxSpots];
        Arrays.fill(occupied , false);
        for(int i = 0 ; i < maxSpots ; i++) {
            if(i % 50 == 0) {
                spots[i] = new Spot(SpotSize.LARGE);
            }
            else if(i % 5 == 0) {
                spots[i] = new Spot(SpotSize.SMALL);
            }
            else {
                spots[i] = new Spot(SpotSize.MEDIUM);
            }
        }
    }

    public boolean park(Vehicle vehicle) {
        if(availableSpots < vehicle.spotsNeeded()) {
            return false;
        }
        int spotNumber = findAvailableSpot(vehicle);
        if(spotNumber < 0) {
            return false;
        }

        parkThatInSpot(vehicle , spotNumber);
        return true;
    }

    private void parkThatInSpot(Vehicle vehicle, int spotNumber) {
        availableSpots -= vehicle.spotsNeeded();
        for(int i = spotNumber ; i < maxSpots ; i++) {
            occupied[i] = true;
        }
        return ;
    }

    private int findAvailableSpot(Vehicle vehicle) {
        int spotsNeeded = vehicle.spotsNeeded();
        for(int i = 0 ; i < maxSpots ; i++) {
            if(occupied[i] == false) {
                int index = i;
                int count = 0;
                while(index < maxSpots) {
                    if(occupied[index] == false) {
                        index++;
                        count++;
                    }
                    else break;
                    if(count == spotsNeeded) {
                        break;
                    }
                }

                if(count == spotsNeeded) return i;
                i = index;
            }
        }

        return -1;
    }
}
