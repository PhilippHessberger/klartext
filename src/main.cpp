#include <iostream>
#include <iomanip> // Für schöneres Output-Formatting
#include "klartext/api_client.hpp"

int main() {
    klartext::ApiClient client;
    
    std::cout << "========================================" << std::endl;
    std::cout << "   KLARTEXT: Aktuelle Gesetzgebung      " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Rufe Daten vom Bundestag ab...\n" << std::endl;

    auto gesetze = client.fetchAktuelleGesetze();

    if (gesetze.empty()) {
        std::cout << "Keine Daten gefunden oder API-Fehler." << std::endl;
        return 1;
    }

    for (const auto& g : gesetze) {
        std::cout << "[ID: " << g.id << "]" << std::endl;
        std::cout << "Titel:  " << g.titel << std::endl;
        std::cout << "Status: " << g.beratungsstand << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    return 0;
}