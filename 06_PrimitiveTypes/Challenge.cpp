void challenge() {
	const double price_per_small_room{ 25 };
	const double price_per_large_room{ 35 };
	const double tax_rate{ 6 };
	const short estimate_validity{ 30 };

	cout << endl << endl;
	cout << "Hello, welcome to Arno's Carpet Cleaning Service";
	cout << endl << endl;
	cout << "How many small rooms would you like cleaned?";

	int small_rooms{ 0 };
	cin >> small_rooms;

	cout << "How many large rooms you like cleaned?";

	int large_rooms{ 0 };
	cin >> large_rooms;

	double cost = (small_rooms * price_per_small_room) + (large_rooms * price_per_large_room);
	double total_estimate = cost + cost * (tax_rate / 100);

	cout << endl << endl;
	cout << "Estimate for carpet cleaning service" << endl;
	cout << "Number of small rooms: " << small_rooms << endl;
	cout << "Number of large rooms: " << large_rooms << endl;
	cout << "Price per small room: $" << price_per_small_room << endl;
	cout << "Price per large room: $" << price_per_large_room << endl;
	cout << "Cost: $" << cost << endl;
	cout << "Taxes: " << tax_rate << "%" << endl;
	cout << "======================================" << endl;
	cout << "Total estimate: $" << total_estimate << endl;
	cout << "This estimate is valid for " << estimate_validity << "days";
	cout << endl << endl;
}