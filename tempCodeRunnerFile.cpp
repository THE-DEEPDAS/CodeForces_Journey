
                pq.pop(); // Remove it from the heap
                
                processedCustomers++; // Increment processed customer count
                if (maxCars > 1) {
                    remainingCars.push_back(maxCars - 1); // Store remaining cars