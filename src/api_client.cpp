#include "klartext/api_client.hpp"
#include <cpr/cpr.h>
#include <iostream>

namespace klartext {

std::vector<Vorgang> ApiClient::fetchAktuelleGesetze() {
    const std::string url = "https://search.dip.bundestag.de/api/v1/vorgang";
    const std::string apiKey = "OSOegLs.PR2lwJ1dwCeje9vTj7FPOt3hvpYKtwKkhw";

    auto response = cpr::Get(
        cpr::Url{url},
        cpr::Header{{"Authorization", "ApiKey " + apiKey}},
        cpr::Parameters{{"f.vorgangstyp", "Gesetzgebung"}, {"limit", "10"}}
    );

    std::vector<Vorgang> liste;

    if (response.status_code == 200) {
        auto data = nlohmann::json::parse(response.text);
        for (const auto& doc : data["documents"]) {
            liste.push_back({
                doc.value("id", ""),
                doc.value("titel", "Kein Titel"),
                doc.value("beratungsstand", "Unbekannt"),
                doc.value("initiator", "Unbekannt") // Wer hat es gestartet?
            });
        }
    } else {
        std::cerr << "Fehler: API nicht erreichbar. Status: " << response.status_code << std::endl;
    }

    return liste;
}

} // namespace klartext
