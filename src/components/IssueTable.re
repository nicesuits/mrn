let component = ReasonReact.statelessComponent("IssueTable");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      {ReasonReact.string("This is a placeholder for the issue table.")}
    </div>,
};