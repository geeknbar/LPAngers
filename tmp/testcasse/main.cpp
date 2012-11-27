#include <iostream> // std::cout, std::cin
#include <fstream> // std::ifstream, std::ofstream
#include <sstream> // std::ostringstream
#include <locale> // std::tolower, std::toupper, std::islower, std::isalpha
#include <algorithm> // std::rotate_copy, std::count_if, std::unique, std::remove_if
#include <functional> // std::bind2nd, std::binary_function, std::unary_function
#include <stdexcept> // std::logic_error, std::runtime_error
#include <limits> // std::numeric_limits
#include <cmath> // std::abs
#include <map> // std::map
#include <utility> // std::pair, std::make_pair
#include <string> // std::string

class Caesar
{
    public:

        /* Typedef */
        typedef int gap_type;

        /* Constructor */
        Caesar(const std::string &String = "")
        {
            Assign(String);
        }

        /* Affector */
        Caesar &operator=(const std::string &String)
        {
            Assign(String);
            return *this;
        }

        /* Assignator */
        void Assign(const std::string &String)
        {
            myString = String;
        }

        /* From a file */
        void LoadFromFile(const std::string &Name)
        {
            std::ifstream Ifs(Name.c_str());
            if(!Ifs)
                throw std::runtime_error(
                    "Impossible d'ouvrir le fichier en lecture");

            std::ostringstream Oss;
            Oss << Ifs.rdbuf();

            Assign(Oss.str());
        }

        /* Apply the caesar cipher */
        std::string Apply(gap_type Gap) const
        {
            /* Check */
            bool PGap = Gap > 0;
            Gap = std::abs(Gap) % 26;
            if(Gap == 0 or myString.empty())
                return myString;

            /* Constant */
            typedef std::string::size_type size_type;
            const size_type Size = myString.size();

            /* Tables */
            const std::string Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            gap_type Mid = PGap ? Gap : 26 - Gap;
            std::string Replace;
            std::rotate_copy(Table.begin(), Table.begin() + Mid,
                Table.end(), std::back_inserter(Replace));

            /* Cipher */
            std::string R;
            for(size_type i = 0; i < Size; ++i)
            {
                const bool IsLower = std::islower(myString[i]);
                const size_type I = Table.find(std::toupper(myString[i]));
                if(I != std::string::npos)
                    R += IsLower ? std::tolower(Replace[I])
                        : Replace[I];
                else
                    R += myString[i];
            }

            /* End */
            return R;
        }

    private:

        /* Predicat for count_if() */
        struct NoCaseMatch
        : std::binary_function<char, char, bool>
        {
            bool operator()(char CS, char C) const
            {
                return std::toupper(CS) == C;
            }
        };

    public:

        /* Resolve (frequency analysis with C) */
        std::string Resolve(char C) const
        {
            /* Get F */
            /* This is not the best method because
               if two letter have the same frequency
               the second letter is unused, but that
               isn't a problem */
            std::pair<char, size_t> F; // Most frequency letter
            const std::string Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            for(size_t i = 0; i < Table.size(); ++i)
            {
                const char C = Table[i];
                size_t R = std::count_if(myString.begin(), myString.end(),
                    std::bind2nd(NoCaseMatch(), C));

                if(R > F.second)
                    F = std::make_pair(C, R);
            }

            /* Build resolved string */
            return Apply(C - F.first);
        }

    private:

        /* Data member */
        std::string myString;
};

/* Command line options */
class CLOption
{
    public:

        /* Constructor */
        CLOption(int argc, char *argv[])
        : myApply(false)
        , myIsAFile(false)
        , myManual(false)
        {
            /* No arg */
            if(argc <= 1)
            {
                myManual = true;
                return;
            }

            /* Else */
            bool ApplyOrResolveCall = false;
            std::string Buf;
            for(int i = 1; i < argc; ++i)
            {
                Buf = argv[i];

                /* Filename */
                if(Buf == "-f")
		{
		    /* Check */
		    if(myIsAFile)
			throw std::logic_error(
			    "Le parametre -f a ete trouve plusieurs fois");

                    myIsAFile = true;
		}

                /* Apply */
                else if(Buf == "-a")
                {
                    /* Check */
                    if(myApply or ApplyOrResolveCall)
                        throw std::logic_error(
                            "Les parametres -r et/ou -a ont ete trouves plusieurs fois");

                    myApply = true;
                    ApplyOrResolveCall = true;
                }

                /* Resolve */
                else if(Buf == "-r")
                {
                    /* Check */
                    if(ApplyOrResolveCall)
                        throw std::logic_error(
                            "Les parametres -r et/ou -a ont ete trouves plusieurs fois");

                    myApply = false;
                    ApplyOrResolveCall = true;
                }

                /* Append to myString */
                else
                    myString += Buf;
            }

            /* Check */
            if(myString.empty())
                throw std::logic_error("Le parametre chaine n'a pas ete trouve");
            if(!ApplyOrResolveCall)
                throw std::logic_error("Aucun parametre -a ou -r trouve");
        }

        /* Accessor */
        const std::string &String(void) const
        {
            return myString;
        }

        bool Apply(void) const
        {
            return myApply;
        }

        bool IsAFile(void) const
        {
            return myIsAFile;
        }

        bool ShowManual(void) const
        {
            return myManual;
        }

    private:

        /* Data member */
        std::string myString;
        bool myApply; // if myApply -> apply else resolve
        bool myIsAFile; // if myString is a filename
        bool myManual; // show the "man"
};

/* 2 choice (yes/no) */
bool IsYes(const std::string &Q)
{
    int R = -1;
    while(R != 0 and R != 1)
    {
        std::cout << "> " << Q << " (1 = oui, 0 = non) ? " << std::flush;
        if(!(std::cin >> R))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return R == 1;
}

/* Gap choice */
Caesar::gap_type GetGap(const std::string &Q)
{
    Caesar::gap_type R = 0;
    while(R == 0)
    {
        std::cout << "> " << Q << " (0 interdit) ? " << std::flush;
        if(!(std::cin >> R))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            R = 0;
        }
    }
    return R;
}

/* Letters choice */
struct NoAlpha
: std::unary_function<char, bool>
{
    bool operator()(char C) const
    {
        return !std::isalpha(C);
    }
};

std::string GetLetters(const std::string &Q)
{
    std::cout << "> " << Q << " ? " << std::flush;

    std::string Buf;
    std::getline(std::cin, Buf);

    Buf.erase(std::remove_if(Buf.begin(), Buf.end(), NoAlpha()), Buf.end());
    for(size_t i = 0; i < Buf.size(); ++i)
        Buf[i] = std::toupper(Buf[i]);
    Buf.erase(std::unique(Buf.begin(), Buf.end()), Buf.end());

    return Buf;
}

/* Save in a file */
void SaveInFile(const std::string &Name, const std::string &String,
    const std::string &Extention)
{
    std::cout << "> Sauvegarde de \"" << (Name + Extention) << "\"... "
              << std::flush;

    std::ofstream Ofs((Name + Extention).c_str());
    if(!Ofs)
        throw std::runtime_error("Impossible d'ouvrir le fichier en ecriture");

    Ofs << String;

    std::cout << "OK" << std::endl;
}

int main(int argc, char *argv[])
{
    try
    {
        std::cout << "> Chiffrement de Cesar" << std::endl
                  << "> --------------------\n" << std::endl;

        /* Options of the command line */
        CLOption Options(argc, argv);

        /* Manual */
        if(Options.ShowManual())
        {
            std::cout << "> Synopsis : caesar [-f] _string_ -a|-r\n\n"
                         "> _string_ : chaine de caractere, a entourer "
                                      "d'apostrophes si possible\n"
                         "> -f : Indique si _string_ est un nom de fichier\n"
                         "> -a : Appliquer un (de)chiffrement a _string_\n"
                         "> -r : Resoudre _string_ a l'aide d'une "
                                "analyse frequencielle"
                      << std::endl;

            return 0;
        }

        /* Caesar cipher */
        Caesar Cipher;
        if(Options.IsAFile())
        {
            std::cout << "> Chargement du fichier : \"" << Options.String()
                      << "\" ... " << std::flush;
            Cipher.LoadFromFile(Options.String());
        }
        else
        {
            std::cout << "> Chargement... " << std::flush;
            Cipher = Options.String();
        }
        std::cout << "OK" << std::endl;

        /* Action */
        if(Options.Apply())
        {
            /* Apply */
            Caesar::gap_type Gap = GetGap("Decalage");
            std::cout << "> Traitement (decalage de " << Gap
                      << ")... " << std::flush;
            std::string Applied = Cipher.Apply(Gap);
            std::cout << "OK" << std::endl;

            /* Show results */
            std::cout << "> Resultat apres decalage :\n" << Applied << std::endl;

            /* Save */
            if(Options.IsAFile())
            {
                if(IsYes("Voulez-vous sauvegarder le fichier"))
                {
                    std::ostringstream Oss;
                    Oss << "." << Gap << ".applied";
                    SaveInFile(Options.String(), Applied, Oss.str());
                }
            }
        }
        else
        {
            /* Resolve */
            typedef std::map<char, std::string> map_type;
            map_type Resolved;
            std::string Letters = GetLetters(
                "Quelles lettres utiliser pour l'analyse");
            std::cout << "> Traitement (analyse frequencielle)... " << std::flush;
            for(size_t i = 0; i < Letters.size(); ++i)
                Resolved[Letters[i]] = Cipher.Resolve(Letters[i]);
            std::cout << "OK" << std::endl;

            /* Show results */
            std::cout << "> Resultats apres resolution avec " << Letters
                      << " :" << std::endl;
            typedef map_type::const_iterator resolved_iterator;
            for(resolved_iterator It = Resolved.begin(); It != Resolved.end();
                ++It)
            {
                std::cout << "> " << It->first << " :\n" << It->second
                          << std::endl;
            }
            std::cout << "> Si aucune de ces solutions ne convient, "
                           "c'est peut-etre à cause du texte\n"
                         "> trop court ou à cause de l'utilisation "
                           "de mauvaises lettres, essayez\n"
                         "> avec d'autres lettres"
                      << std::endl;

            /* Save */
            if(Options.IsAFile())
            {
                std::string SaveLetters = GetLetters(
                    "Voulez-vous sauvegarder "
                    "(entrez les lettres qui vous interressent)");

                for(resolved_iterator It = Resolved.begin();
                    It != Resolved.end(); ++It)
                {
                    if(SaveLetters.find(It->first) != std::string::npos)
                    {
			std::ostringstream Oss;
                        Oss << "." << It->first << ".resolved";
                        SaveInFile(Options.String(), It->second, Oss.str());
                    }
                }
            }
        }
    }
    catch(const std::exception &E)
    {
        std::cout << "\n> Erreur.. " << E.what() << std::endl
                  << "> De...... " << typeid(E).name() << std::endl;

        return 1;
    }
    catch(...)
    {
        std::cout << "\n> Erreur.. Inconnue" << std::endl
                  << "> De...... " << std::endl;

        return 1;
    }

    return 0;
}
