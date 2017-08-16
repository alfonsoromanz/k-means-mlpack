#include <mlpack/core.hpp>
#include <cmath>
#include <mlpack/methods/kmeans/kmeans.hpp>

using namespace mlpack;
using namespace mlpack::kmeans;
//using namespace mlpack::metric;

int main()
{
    
    arma::mat data; // Alojara el Dataset

    arma::Row<size_t> assignments; // Tendra las asignaciones finales

    arma::mat centroids; // Tendra los centroides finalez
    
    /*
     * Carga el dataset especificado en la matriz "data"
     */
    data::Load("data.csv", data, true);

    
    /* 
     * Parametros del algoritmo
     */

    int max_iterations = 100;
    int k = 2;


    /*
     * Modelo k-means
     */

    KMeans<> k_means(max_iterations);

    k_means.Cluster(data, k, centroids);
    

    
    // Print out each neighbor and its distance.
    for (size_t i = 0; i < centroids.n_elem; ++i)
    {
        std::cout << "Centroide " << i << " es "
        << centroids[i] << ".\n";
    }
}
