(function () {
  farmOS.map.behaviors.farm_map_skagit = {
    attach: function (instance) {

      // Check if any layers are provided.
      if (typeof Drupal.settings.farm_map.behaviors.farm_map_skagit.layers !== 'undefined') {

        // Get layers from settings.
        var layers = Drupal.settings.farm_map.behaviors.farm_map_skagit.layers;

        // Add map layer for each provided via settings.
        layers.forEach(function(layer) {
          var opts = {
            title: "Skagit " + layer.name.split('/')[1],
            url: 'https://www.skagitcounty.net/gispublic/rest/services/' + layer.name + '/' + layer.type,
            visible: false,
            base: true,
            group: 'Base layers',
          };
          instance.addLayer('arcgis-tile', opts);
        });
      }
    },
  };
}());
