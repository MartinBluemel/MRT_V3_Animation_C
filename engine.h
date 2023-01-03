#ifndef _engine_H_
#define _engine_H_


#include"newdata.h"

// Engine Schnittstelle
/*calculate_next_pic: Funktion um pixelweise den nächsten Aniamtionspuffer zu berechnen
 *Berechnungsvorschriften:
 * - freier Pixel mit exakt 3 belegten Nachbarpixeln wird zu belegten Pixel
 * - belegter Pixel mit zwei oder drei belegten Nachbarpixeln bleibt belegt
 * - belegter Pixel mit mehr als drei belegten Nachbarpixeln wird frei
 * - belegter Pixel mit weniger als zwei belegten Nachbarpixeln wird frei
 */
struct Laufzeitdaten calculate_next_pic(struct Laufzeitdaten caldata);


#endif //ENGINE_HH
