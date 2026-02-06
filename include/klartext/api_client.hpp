#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace klartext {

struct Vorgang {
    std::string id;
    std::string titel;
    std::string beratungsstand;
    std::string abstract;
    std::vector<std::string> schlagworte;
    // std::string urheber;
};

class ApiClient {
public:
    // Holt die aktuellsten 10 Gesetzgebungs-Vorgänge
    std::vector<Vorgang> fetchAktuelleGesetze();
};

} // namespace klartext