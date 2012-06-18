<div class="panel-display omega-grid omega-12-threecol-3-9-stacked" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel grid-9 push-3">
    <div class="inside"><?php print $content['top']; ?>
      <div class="panel-panel grid-6 alpha">
        <div class="inside"><?php print $content['center']; ?></div>
      </div>
      <div class="panel-panel grid-3 omega">
        <div class="inside"><?php print $content['right']; ?> </div>
      </div>
    </div>
  </div>
  <div class="panel-panel grid-3 pull-9">
    <div class="inside"><?php print $content['left']; ?> </div>
  </div>
</div>
